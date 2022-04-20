module.exports = {
	name: 'settings',
	description: 'showing settings',
	aliases: ['set', 'setting'],
	execute(message, args) {
		// message.channel.send(`> Your id is ${message.author.id}`);
    message.channel.send(`> This server's name is: ${message.guild.name}\n> ${message.author.username}, nice to meet you😊\n> I have the following functions:\n> \`$delete <number>\` -- to delete previous messages\n> \`$random\` -- to generate a random number\n> \`$bombard @someone\` -- to bombard someone\n> \`$damn @someone\` -- to blame someone\n> \`$happeejai\` -- to generate golden quotes\n> \`$testlie\` -- to test if your statement is true or not\n> \`$inspire\` -- to get inspired by QUOTES\n> \`$chinese+\` or \`$chinese-\` -- to do revision`);
	},
};
