module.exports = {
	name: 'damn',
	description: 'damning a user',
	cooldown:10,
	aliases: ['dmn','fk','blame','diu','nmsl','dllm','on9','87','487'],
	guildOnly: true,
	execute(message, args) {

		if (!message.mentions.users.size) {
			return message.reply('You need to tag a user in order to blame him/her!😊\n> You have to input in the form of $bombard @TheUser\n> eg. $bombard @YourTeacher');
		}
		const damnwords = require('./wordlist.json');
		damnwords.damn.forEach(iterate);
		function iterate(item){
			const taggedUser = message.mentions.users.first();
			let word = item;
			message.channel.send(`> ${taggedUser}${word}`);}
	},
};
