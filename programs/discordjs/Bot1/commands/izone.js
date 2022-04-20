// require the discord.js module
const Discord = require('discord.js');

module.exports = {
	name: 'izone',
	description: 'being funny',
	aliases: ['iz'],
  cooldown:0,
	guildOnly: true,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.izone.length;
		var randomno = Math.floor((Math.random() * numofwords) );
		var src = funnywords.izone[randomno];
		const embed = new Discord.MessageEmbed()
			.setColor('#9f119f')
			.setTitle('❤IzOne❤')
			.setDescription(src)


		//
		message.channel.send(embed);

	}
};
