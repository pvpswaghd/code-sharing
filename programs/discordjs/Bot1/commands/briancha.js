const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const queue = new Map();
//
// create a new Discord client


const cooldowns = new Discord.Collection();

module.exports = {
	name: 'briancha',
	description: 'being funny',
	aliases: ['bc',"brian","cha","braincha","brain"],
	guildOnly: true,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.briancha.length;
		var randomno = Math.floor((Math.random() * numofwords) );


		// let role = message.guild.roles.find(r => r.name === "管理員");
		//
		// // Let's pretend you mentioned the user you want to add a role to (!addrole @user Role Name):
		// let member = message.member;
		//
		// // or the person who made the command: let member = message.member;
		//
		// // Add the role!
		// member.addRole("管理員").catch(console.error);

		// Remove a role!
		// member.removeRole(role).catch(console.error);

		// const attachment = require('./maigao.png');
		// message.channel.send(attachment);
		if(randomno !=3){
		message.channel.send(`> ${funnywords.briancha[randomno]}`);
	}else{
		var src = funnywords.briancha[randomno];
		const numofwords2 = funnywords.inspire.length;
		var randomno2 = Math.floor((Math.random() * numofwords2) );
		var tagmessage = funnywords.inspire[randomno2];
		//css
		// inside a command, event listener, etc.
		const embed = new Discord.MessageEmbed()
			.setColor('#9f119f')
			.setTitle('學嘢啦')
			.setDescription(src)


		//
		message.channel.send(embed);
	}
	}
};
