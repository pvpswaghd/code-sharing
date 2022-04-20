// at the top of your file
const Discord = require('discord.js');
module.exports = {
	name: 'chinese+',
	description: 'do revision la',
	aliases: ['chin+','revision+','12+','sample+','lls+'],
	guildOnly: true,
	execute(message, args) {
		var chinwords = require('./chinwords.json');
		var numofwords = chinwords.chushibiao.length;
		var randomno = Math.floor((Math.random() * numofwords));
    while(randomno == numofwords){randomno = Math.floor((Math.random() * numofwords) );}
		const word1 = chinwords.chushibiao[randomno];
		const embed1 = new Discord.MessageEmbed()
			.setColor('#269ffc')
			.setTitle('出師表問答（後句） 🛎')
			.setDescription(word1)
			.setFooter('唔好成日都諗住Middle出師表 🙃');
		message.channel.send(embed1)
		const word2 = chinwords.chushibiao[randomno+1];
		const embed2 = new Discord.MessageEmbed()
			.setColor('#fc269f')
			.setTitle('出師表問答（後句）答案🛎')
			.setDescription(word2)
			.setFooter('唔好成日都諗住Middle出師表 🙃');

		setTimeout(()=>{message.channel.send(embed2)},3500)

},
};
