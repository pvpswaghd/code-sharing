const fs = require('fs');

// require the discord.js module
const Discord = require('discord.js');
// for music
const queue = new Map();
//
// create a new Discord client
const {Client, Intents} = require('discord.js');
const client = new Client({ intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES] });
client.commands = new Discord.Collection();

const cooldowns = new Discord.Collection();

module.exports = {
	name: 'blackpink',
	description: 'being funny',
	aliases: ['bp'],
	guildOnly: true,
	cooldown:0,
	execute(message, args) {
		const funnywords = require('./wordlist.json');
		const numofwords = funnywords.blackpink.length;
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

		var src = funnywords.blackpink[randomno];
		const numofwords2 = funnywords.inspire.length;
		var randomno2 = Math.floor((Math.random() * numofwords2) );
		var tagmessage = funnywords.inspire[randomno2];
		//css
		// inside a command, event listener, etc.
		const embed = new Discord.MessageEmbed()
			.setColor('#9f119f')
			.setTitle('❤Blackpink❤')
			.setDescription(src)


		//
		message.channel.send(embed);

	}
};
