module.exports = {
	name: 'happeejai',
	description: 'being funny',
	aliases: ['666','funny','idiot','happy','happyjai','yo'],
	guildOnly: true,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.funny.length;
		var randomno = Math.floor((Math.random() * numofwords) );
		if(randomno != 9 && randomno !=8 && randomno !=10){
		message.channel.send(`> ${funnywords.funny[randomno]}`);
	}else{
		message.channel.send(`${funnywords.funny[randomno]}`);
	}
	}
};
