const { Player } = require('discord-player');
const { Client, Intents, Collection, MessageEmbed, Message } = require('discord.js');
const { readdirSync } = require('fs');

let client = new Client({
    intents: [
        Intents.FLAGS.GUILDS,
        Intents.FLAGS.GUILD_MEMBERS,
        Intents.FLAGS.GUILD_MESSAGES,
        Intents.FLAGS.GUILD_VOICE_STATES
    ]
});

client.config = require('./config');
client.player = new Player(client, client.config.opt.discordPlayer);
client.commands = new Collection();
const player = client.player

const events = readdirSync('./events/').filter(file => file.endsWith('.js'));
for (const file of events) {
    const event = require(`./events/${file}`);
    console.log(`-> Loaded event ${file.split('.')[0]}`);
    client.on(file.split('.')[0], event.bind(null, client));
    delete require.cache[require.resolve(`./events/${file}`)];
};
console.log(`-> Loaded commands...`);
readdirSync('./commands/').forEach(dirs => {
    const commands = readdirSync(`./commands/${dirs}`).filter(files => files.endsWith('.js'));
    for (const file of commands) {
        const command = require(`./commands/${dirs}/${file}`);
        console.log(`${command.name.toLowerCase()} Load Command!`);
        client.commands.set(command.name.toLowerCase(), command);
        delete require.cache[require.resolve(`./commands/${dirs}/${file}`)];
    };
});
const embed = new MessageEmbed();
embed.setColor('BLUE');


player.on('trackStart', (queue, track) => {
    if (!client.config.opt.loopMessage && queue.repeatMode !== 0) return;
    embed.setColor('YELLOW');
    embed.setThumbnail(track.thumbnail);
    embed.setDescription(`**現正播放: ${track.title}** \n長度: ${track.duration}\n`)
    embed.setFooter({text: 'Custom feature by Victor'})
    queue.metadata.send({ embeds: [embed] });
});

player.on('trackAdd', (queue, track) => {
    embed.setThumbnail(track.thumbnail);
    embed.setDescription(`**已加入: ${track.title}** \n長度: ${track.duration}\n`)
    embed.setFooter({text: 'Custom feature by Victor'})
    queue.metadata.send({ embeds: [embed] });
});

player.on('botDisconnect', (queue) => {
    queue.metadata.send({ content: 'Some bitchass kicked me out, me angry playlist deleted ❌' });
});

player.on('channelEmpty', (queue) => {
    queue.metadata.send({ content: '唔做kam撚 酒仙酒仙 ❌' });
});

player.on('queueEnd', (queue) => {
    queue.metadata.send({ content: '**俾錢啦你老母!!!!!!**' });
});



if(client.config.TOKEN){
client.login(client.config.TOKEN).catch(e => {
console.log("The Bot Token You Entered Into Your Project Is Incorrect Or Your Bot's INTENTS Are OFF!")
})
} else {
console.log("Please Write Your Bot Token Opposite The Token In The config.js File In Your Project!")
}
