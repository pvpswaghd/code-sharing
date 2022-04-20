// at the top of your file
const Discord = require('discord.js');
module.exports = {
	name: 'testlie',
	description: 'yes or no',
	aliases: ['test', 'lie','yon'],
	execute(message, args) {
		
		var testresult;
		var name = message.author.username;
		var taggedUser = message.mentions.users.first();
		// message.channel.send(`> Your id is ${message.author.id}`);
		function testlie(){
			var randomno = Math.floor((Math.random() * 2) + 1);
			if (!message.mentions.users.size) {

				switch (randomno){
					case 1:
					testresult = new Discord.MessageEmbed()
						.setColor('#2bfc3c')
						.setTitle(name+', at least I believe in you 👾')
						.setFooter('consider why your friends don\'t  believe in you lol');
						break;
					default:

					//css
					// inside a command, event listener, etc.
					testresult = new Discord.MessageEmbed()
						.setColor('#fc2926')
						.setTitle(name+', YOU LIED 💩')
						.setFooter('human few few admit it la lol');

					//
				}
			}else{
				switch (randomno){
					case 1:
					// const embed1 = new Discord.MessageEmbed()
					// 	.setColor('#2bfc3c')
					// 	.setTitle(`${taggedUser}, at least I believe in you 👾`)
					// 	.setFooter('consider why your friends don\'t  believe in you lol');
					// 	message.channel.send(embed1);	break;
					testresult = `> ${taggedUser}, at least I believe in you 👾`;
					default:

					//css
					// inside a command, event listener, etc.
					// const embed2 = new Discord.MessageEmbed()
					// 	.setColor('#fc2926')
					// 	.setTitle(`${taggedUser}, YOU LIED 💩`)
					// 	.setFooter('human few few admit it la lol');
					// 	message.channel.send(embed2);
					testresult = `> ${taggedUser}, YOU LIED 💩`
					//
				}
			}
		}
		testlie();
				const filter = response => {
				return response.content.toLowerCase() == 'objection'
			};
		message.channel.send(testresult)
		message.channel.send(`Type \`objection\` to re-test`).then(() => {
		message.channel.awaitMessages(filter, { max: 1, time: 30000, errors: ['time'] })
		.then(collected => {
			testlie();
			message.channel.send(`> The re-testing result:`)
			message.channel.send(testresult);
		})
		.catch(collected => {

		});
		});
},
};
// const filter = (reaction, user) => {
// 	return reaction.emoji.name === '👍' && user.id === message.author.id;
// };
//
// message.awaitReactions(filter, { max: 4, time: 60000, errors: ['time'] })
// 	.then(collected => console.log(collected.size))
// 	.catch(collected => {
// 		console.log(`After a minute, only ${collected.size} out of 4 reacted.`);
// 	});
