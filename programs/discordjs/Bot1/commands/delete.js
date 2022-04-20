module.exports = {
	name: 'delete',
	description: 'delete message function',
	aliases: ['delete', 'del'],
	cooldown: 0,
	execute(message, args) {
			const amount = parseInt(args[0]) + 1;
		    if (isNaN(amount)) {
			return message.reply('> That doesn\'t seem to be a valid number.\n> you have to input in the form of $delete [number].\n> eg. $delete 2\n> This means you want to delete the two previous messages.');
		} else if (amount <= 1 || amount > 101) {
		return message.reply('you need to input a number between 1 and 100.');
		}else {
		  message.channel.bulkDelete(amount);
		}
	},
};
