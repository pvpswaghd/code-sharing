const Discord = require('discord.js');
// for music
module.exports = {
	name: 'music',
	description: 'play music',
	aliases: ['play','musics','song','songs','p'],
	guildOnly: true,
	execute(message, args) {
		const voiceChannel = message.member.voice.channel;

		if (!voiceChannel) {
			return message.reply('please join a voice channel first!');
		}
		voiceChannel.join().then(connection => {
			process.on('unhandledRejection', error => console.error('Uncaught Promise Rejection', error));

			const stream = ytdl('https://www.youtube.com/watch?v=LJoCgPxA_fY', { filter: 'audioonly' });
			const dispatcher = connection.play(stream);

			dispatcher.on('finish', () => voiceChannel.leave());
		});
		process.on('unhandledRejection', error => console.error('Uncaught Promise Rejection', error));
}
};
