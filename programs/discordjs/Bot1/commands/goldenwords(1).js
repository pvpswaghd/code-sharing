module.exports = {
	name: 'goldenwords',
	description: 'getting inspired by golden words',
	aliases: ['rescue','words','word','inspire','goldenword'],
	guildOnly: true,
	execute(message, args) {
		var randomno = Math.floor((Math.random() * 36) + 1);
		
		switch (randomno){
		case 1:message.channel.send(`> 處事獨立和堅強是種責任，做人不愠不火不失温柔是種美德。`);
		break;case 2:message.channel.send(`> 你失落在地球一方，我剛巧穿越千年找到你。歲月荒唐從此有了限期。`);
		break;case 3:message.channel.send(`> 人生已經足夠動盪，所以世人鍾愛平凡。`);
		break;case 4:message.channel.send(`> 時間沒有被快撥，而是一點一滴剛好走到該告別的點數。圍觀着時鐘的人沒有察覺，因為時間一直將我們包圍。`);
		break;case 5:message.channel.send(`> 森林探戈，努力地追尋芳蹤，捉不緊，也快樂過。牠們是自由的。我們也有選擇追逐與否的權利。這種平等千絲萬縷成無常。`);
		break;case 6:message.channel.send(`> 一個人的孤單是兩個人的故事。`);
		break;case 7:message.channel.send(`> 我是如此喜歡森林和海洋，\n> 因為在藍天白雲的應允下，\n> 我們能夠抹去名字，真正對話。`);
		break;case 8:message.channel.send(`> 孤單和狂歡的本質都是因爲寂寞。\n> 心若有所失，躲到哪裡都有遺憾。`);
		break;case 9:message.channel.send(`> 坦露與否後，那些本來的壞沒有消失，只不過以後會小心翼翼地被隱藏。`);
		break;case 10:message.channel.send(`> 我們花一生設限，畢生都在等一個例外。`);
		break;case 11:message.channel.send(`> 聽說出生季節早定了我們半生。\n> 春孕萬物，外柔實剛；\n> 生燃於夏，陽剛明媚；\n> 落葉知秋，枯榮自知；\n> 凜冬既至，能者耐寒。`);
		break;case 12:message.channel.send(`> 我們歲月消逝之際，永遠有人正值美好。\n> 生命盡頭之前，被追趕和取代是一種必然的命運。`);
		break;case 13:message.channel.send(`> 站在顛峰的人不可怕，\n> 真正可怕的是拼命追趕的人。`);
		break;case 14:message.channel.send(`> 數學差是早熟的表現。豈只1 加 1 不單是等於 2，1 減 1 也不是 0。凡事、說話或者關係向前走過 1 步，再往後 1 步，永遠也退不到零的原點。`);
		break;case 15:message.channel.send(`> 你是舊城的莊嚴肅穆，我是屬於民間的歌舞昇平。你的不惑，和我的不解相視，是凜冬將盡仍未卸下的那一場初雪。`);
		break;case 16:message.channel.send(`> 如果有日，所有的欲言又止也能雲淡風輕地吐露，那背後的糾結大概已經釋懷。真相亦失去價值。`);
		break;case 17:message.channel.send(`> 這已不再關乎第六感準確與否乎。\n\n> 當第六感的雷達一旦出現負面感應，\n> 不安感即已產生，關係的變化已半成定局。\n> —— 太過仰賴第六感的你們我們。`);
		break;case 18:message.channel.send(`> 這座城市流浪著幾多被拒諸門外仍流竄不滅的真心。\n> 我看見了，你有沒有？`);
		break;case 19:message.channel.send(`> 有些人一直都在，只是「在」的距離和形式有了變化。`);
		break;case 20:message.channel.send(`> | 霧裏看花 |\n> 迷信心理測驗的人，大概前題都相信人具「潛意識」。人在答題時作出看似不相干的選擇，實是其潛在意識中的一種反射，同時具其他代表意義。從而藉此去解讀一個人。\n> 只要開始深信人有「潛意識」，日子裏的種種選擇都難免被放大，視作一種本能的思想反射。`);
		break;case 21:message.channel.send(`> 當時間已經走了大半圈，有人還執意地加倍努力創造奇蹟。過程有多痛苦，體會就有多深刻。\n> 萬事萬物都有個等號，就看你是否願意等價交換。`);
		break;case 22:message.channel.send(`> 如果我如期歸來，那個我將一去不返。`);
		break;case 23:message.channel.send(`> 因為真心，所以我的愛和存在，不需證明。`);
		break;case 24:message.channel.send(`> 有沒有一種花，花開不落地？`);
		break;case 25:message.channel.send(`> 時間都往前了，你卻把自己遺落在原地。`);
		break;case 26:message.channel.send(`> 因為真心，所以我的愛和存在，不需證明。`);
		break;case 27:message.channel.send(`> 可惜了一段關係，共了患難，敵不過時間。`);
		break;case 28:message.channel.send(`> 衝突源於各自期望的不同，又互不體諒。\n> 你說，我們總沒可能要求全世界的理解。\n> 可是，為了避免衝突，你避免了一切的期望與堅持。`);
		break;case 29:message.channel.send(`> 久而久之，彷彿失去了和世界抗辯的能力。\n> 我們改善了科技，科技改變了我們。`);
		break;case 30:message.channel.send(`> 孤單不過是思念無聲的回音。`);
		break;case 31:message.channel.send(`> 想要守護你未來的快樂，即使永遠先行退場。`);
		break;case 32:message.channel.send(`> 你對世界温柔以待，你亦期望世界待你如許。今後，收好你的期待，繼續你的温柔。`);
		break;case 33:message.channel.send(`> 重要的是，生命的最後你想擁有了什麼，並非擁有着什麼。`);
		break;case 34:message.channel.send(`> 我們年輕，總急著表達自己，渴求理解。`);
		break;case 35:message.channel.send(`> 我們都誤解了「永遠」。「永遠」不是一輩子的時長。一眼可以萬年，一晃便是永遠。「永遠」是一切擁有意識的瞬間。`);
		break;default:message.channel.send(`> 如果老去沒使我變得更美麗，那是年輕時我的過失。`)	}
},
};
// execute(message, args) {
// 	message.channel.send(`> 爹親娘親不及黨親`);
// 	message.channel.send(`> 習近平新時代中國特色社會主義思想`);
// 	message.channel.send(`> 永遠跟隨黨的步伐走`);
// 	message.channel.send(`> 人民公社好`);
// 	message.channel.send(`> 國家非常欣賞你`);
// 	message.channel.send(`> 陳獨秀同學請坐下`);
// 	message.channel.send(`> 震驚14 億人`);
// 	message.channel.send(`> 傑出的一手`);
// 	message.channel.send(`> 五星红旗迎風飄揚\n> 勝利歌聲多麼響亮\n> 歌唱我們親爱的祖国\n> 從此走向繁榮富强`);
// 	message.channel.send(`> ⠄⠄⠄⠄⠄⠄⢠⣿⣋⣿⣿⣉⣿⣿⣯⣧⡰⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⣿⣿⣹⣿⣿⣏⣿⣿⡗⣿⣿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠟⡛⣉⣭⣭⣭⠌⠛⡻⢿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⠄⣤⡌⣿⣷⣯⣭⣿⡆⣈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣷⢛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⠄⢻⣷⣽⣿⣿⣿⢿⠃⣼⣧⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣛⣻⣿⠟⣀⡜⣻⢿⣿⣿⣶⣤⡀⠄⠄⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⠄⢠⣤⣀⣨⣥⣾⢟⣧⣿⠸⣿⣿⣿⣿⣿⣤⡀⠄⠄⠄\n> ⠄⠄⠄⠄⠄⠄⠄⠄⢟⣫⣯⡻⣋⣵⣟⡼⣛⠴⣫⣭⣽⣿⣷⣭⡻⣦⡀⠄\n> ⠄⠄⠄⠄⠄⠄⠄⢰⣿⣿⣿⢏⣽⣿⢋⣾⡟⢺⣿⣿⣿⣿⣿⣿⣷⢹⣷⠄\n> ⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢣⣿⣿⣿⢸⣿⡇⣾⣿⠏⠉⣿⣿⣿⡇⣿⣿⡆\n> ⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢸⣿⣿⣿⠸⣿⡇⣿⣿⡆⣼⣿⣿⣿⡇⣿⣿⡇\n> ⠇⢀⠄⠄⠄⠄⠄⠘⣿⣿⡘⣿⣿⣷⢀⣿⣷⣿⣿⡿⠿⢿⣿⣿⡇⣩⣿⡇\n> ⣿⣿⠃⠄⠄⠄⠄⠄⠄⢻⣷⠙⠛⠋⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⡇⣿⣿⡇`);
// },
// };
