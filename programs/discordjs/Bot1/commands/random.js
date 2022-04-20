module.exports = {
	name: 'random',
	description: 'randomnumber generator',
	execute(message, args) {
    var randomno = Math.floor((Math.random() * 13) + 1);
    message.channel.send("> Your lucky number is " + randomno + "😊");
	},
};
