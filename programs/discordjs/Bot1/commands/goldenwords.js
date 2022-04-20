// at the top of your file
const Discord = require('discord.js');
module.exports = {
	name: 'goldenwords',
	description: 'getting inspired by golden words',
	aliases: ['rescue','words','word','inspire','goldenword'],
	guildOnly: true,
	execute(message, args) {
		const goldenwords = require('./wordlist.json');
		const numofwords = goldenwords.inspire.length;
		var randomno = Math.floor((Math.random() * numofwords) );

		const words = goldenwords.inspire[randomno];
		randomno +=1;
		//css
		// inside a command, event listener, etc.
		const embed = new Discord.MessageEmbed()
			.setColor('#5126fc')
			.setTitle('Quote '+randomno+' 💬')
			.setDescription(words)
			.setFooter('\#goldenwords');

		//

		message.channel.send(embed);

},
};
