// at the top of your file
const Discord = require('discord.js');
module.exports = {
	name: 'bombard',
	description: 'bombarding a user',
	cooldown:0,
	guildOnly: true,
	args:true,
	usage: '@user',
	execute(message, args) {
		// inside a command, event listener, etc.


		//
		const taggedUser = message.mentions.users.first();
		if (!message.mentions.users.size) {
			return message.reply('You need to tag a user in order to bombard him/her!😊\n> You have to input in the form of $bombard @TheUser\n> eg. $bombard @YourTeacher');
		}
		for (i=1;i<=10;i++){
			message.channel.send(`> Get up la ${taggedUser}, it's 10:30`);
		}
	},
};
