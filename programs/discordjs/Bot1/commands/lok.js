const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const queue = new Map();
//
// create a new Discord client

const cooldowns = new Discord.Collection();

module.exports = {
	name: 'lok',
	description: 'being funny',
	aliases: ['lokk'],
	guildOnly: true,
	execute(message, args) {


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
		message.channel.send(`@壽星仔 @hk_lok#9828 Happy birthday!`);

	}
};
