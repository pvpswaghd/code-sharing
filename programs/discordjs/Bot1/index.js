const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const queue = new Map();
//
const { prefix, token, directory, admin, robotid} = require('./config.json');
// create a new Discord client
const {Client, Intents} = require('discord.js');
const client = new Client({ intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES] });

client.commands = new Discord.Collection();

const cooldowns = new Discord.Collection();

const config = require('./config.json');



client.login(token);

const commandFiles = fs.readdirSync(directory).filter(file => file.endsWith('.js'));
// //css
// // inside a command, event listener, etc.
// const embed = new Discord.MessageEmbed()
// 	.setColor('#0099ff')
// 	.setTitle('Some title')
// 	.setURL('https://discord.js.org/')
// 	.setAuthor('Some name', 'https://i.imgur.com/wSTFkRM.png', 'https://discord.js.org')
// 	.setDescription('Some description here')
// 	.setThumbnail('https://i.imgur.com/wSTFkRM.png')
// 	.addFields(
// 		{ name: 'Regular field title', value: 'Some value here' },
// 		{ name: '\u200B', value: '\u200B' },
// 		{ name: 'Inline field title', value: 'Some value here', inline: true },
// 		{ name: 'Inline field title', value: 'Some value here', inline: true },
// 	)
// 	.addField('Inline field title', 'Some value here', true)
// 	.setImage('https://i.imgur.com/wSTFkRM.png')
// 	.setTimestamp()
// 	.setFooter('Some footer text here', 'https://i.imgur.com/wSTFkRM.png');
//
// //
// when the client is ready, run this code
// this event will only trigger one time after logging in
client.once('ready', () => {
	console.log('The Bot1 is online');
});

for (const file of commandFiles) {
	const command = require(`./commands/${file}`);

	// set a new item in the Collection
	// with the key as the command name and the value as the exported module
	client.commands.set(command.name, command);
}

client.on('message', message => {
	if (!message.content.startsWith(prefix) && message.mentions.users.first() == robotid){
		message.react('🙃');
	}
  if (!message.content.startsWith(prefix) || message.author.bot) return;

  // const args = message.content.slice(prefix.length).split(' ');
  const args = message.content.slice(prefix.length).split(/ +/);
  const commandName = args.shift().toLowerCase();
	// if(commandName == 'play'){
	// 	const voiceChannel = message.member.voice.channel;
	//
	// 	if (!voiceChannel) {
	// 		return message.reply('please join a voice channel first!');
	// 	}
	//
	// 	voiceChannel.join().then(connection => {
	// 		const stream = ytdl('https://www.youtube.com/watch?v=D57Y1PruTlw', { filter: 'audioonly' });
	// 		const dispatcher = connection.play(stream);
	//
	// 		dispatcher.on('finish', () => voiceChannel.leave());
	// 	});
	// }
	const command = client.commands.get(commandName)
		|| client.commands.find(cmd => cmd.aliases && cmd.aliases.includes(commandName));
		try{
			if (command.args && !args.length) {
			let reply = `You didn't provide any arguments, ${message.author}!🙃`;

			if (command.usage) {
				reply += `\nThe proper usage would be: \`${prefix}${command.name} ${command.usage}\`😊`;
			}

			return message.channel.send(reply);}
		}catch(err){
			return
		}
	if (!command) return;


	if (!cooldowns.has(command.name)) {
		cooldowns.set(command.name, new Discord.Collection());
	}

	const now = Date.now();
	const timestamps = cooldowns.get(command.name);
	var isadmin = false;
	for (var checkingadmin = 0; checkingadmin < admin.length; checkingadmin++){
	if (message.author.id === admin[checkingadmin]){
		isadmin = true}
	}
	if (isadmin == true){
		var cooldownAmount = 10;
	}else {
	var cooldownAmount = (command.cooldown || 3) * 1000;}

	if (timestamps.has(message.author.id)) {
	const expirationTime = timestamps.get(message.author.id) + cooldownAmount;

	if (now < expirationTime) {
		const timeLeft = (expirationTime - now) / 1000;
		return message.reply(`please wait ${timeLeft.toFixed(0)} more second(s) before reusing the \`${command.name}\` command! 🐢`);
	}
}
timestamps.set(message.author.id, now);
setTimeout(() => timestamps.delete(message.author.id), cooldownAmount);
try {
	command.execute(message, args);
} catch (error) {
	console.error(error);
	message.reply('there was an error trying to execute that command!');
}
//   if (message.content.startsWith(`${prefix}randomnumber`)) {
//     client.commands.get('randomnumber').execute(message, args);
//   } else if (message.content.startsWith(`${prefix}beep`)) {
//   	message.channel.send('Boop.');
//   } else if (message.content === `${prefix}setting`) {
// 	message.channel.send(`This server's name is: ${message.guild.name}\n${message.author.username}, nice to meet you😊`);
// }
// else if (command === 'kick') {
// // grab the "first" mentioned user from the message
// // this will return a `User` object, just like `message.author`
// const taggedUser = message.mentions.users.first();
// if (!message.mentions.users.size) {
// 	return message.reply('you need to tag a user in order to kick them!');
// }
// message.channel.send(`You wanted to kick: ${taggedUser.username}`);
// }else if (command === 'delete') {
// 	const amount = parseInt(args[0]) + 1;
//
//     if (isNaN(amount)) {
// 	return message.reply('that doesn\'t seem to be a valid number.');
// } else if (amount <= 1 || amount > 100) {
// return message.reply('you need to input a number between 1 and 99.');
// }else {
//   message.channel.bulkDelete(amount);
// }
// 	}
//
// // using the new `command` variable, this makes it easier to manage!
// // you can switch your other commands to this format as well
// // else if (command === 'args-info') {
// // 	if (!args.length) {
// // 		return message.channel.send(`You didn't provide any arguments, ${message.author}!`);
// // 	}
// //
// // 	message.channel.send(`Command name: ${command}\nArguments: ${args}`);
// // }
// // });
// else if (command === 'args-info') {
// 	if (!args.length) {
// 		return message.channel.send(`You didn't provide any arguments, ${message.author}!`);
// 	}
// 	else if (args[0] === 'foo') {
// 		return message.channel.send('bar');
// 	}
//
// 	message.channel.send(`First argument: ${args[0]}`);
// }

});
// login to Discord with your app's token
client.login(token);

/*
node C:\Users\user\Documents\GoogleDrive\coding\coding_discord\Bot1\index.js
*/
