const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const queue = new Map();
//
// create a new Discord client


const cooldowns = new Discord.Collection();

module.exports = {
	name: 'joe',
	description: 'being funny',
	aliases: ['jc'],
	guildOnly: true,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.joe.length;
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
		if(randomno != 0&&randomno!=1&&randomno!=2){message.channel.send(`> ${funnywords.joe[randomno]}`);
	}else{
		if(randomno == 2){randomno = 1}
		var src = funnywords.joe[randomno];
		const numofwords2 = funnywords.inspire.length;
		var randomno2 = Math.floor((Math.random() * numofwords2) );
		var tagmessage = funnywords.inspire[randomno2];
		//css
		// inside a command, event listener, etc.
		const embed = new Discord.MessageEmbed()
			.setColor('#9f1111')
			.setTitle('❤Proposal Card❤')
			.setDescription(src)
			.setFooter('\#'+tagmessage);

		//
		message.channel.send(embed);
	}

	}
};
