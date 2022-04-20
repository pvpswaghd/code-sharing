const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const ytdl = require("ytdl-core");
const queue = new Map();
//
// create a new Discord client
const client = new Discord.Client();

client.commands = new Discord.Collection();

const cooldowns = new Discord.Collection();

module.exports = {
	name: 'cyt魚錄',
	description: 'being funny',
	aliases: ['cyt'],
	guildOnly: true,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.cyt.length;
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
		message.channel.send(`> ${funnywords.cyt[randomno]}`);

	}
};
