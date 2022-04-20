module.exports = {
    name: 'skip',
    aliases: [],
    utilisation: '{prefix}skip',
    voiceChannel: true,

    execute(client, message) {
        const queue = client.player.getQueue(message.guild.id);
 
        if (!queue || !queue.playing) return message.channel.send({ content: `${message.author}, 完全0歌， 唔知播乜撚❌` });

        const success = queue.skip();

        return message.channel.send({ content: success ? `**屌呢首${queue.current.title}**好難聽吖，忍左你好耐🖕🏻🖕🏻🖕🏻` : `${message.author}, Something went wrong ❌` });
    },
};
