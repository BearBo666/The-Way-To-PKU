const dgram = require("dgram");
const Server = dgram.createSocket("udp4");

// 组播地址
const multi_ip = "225.0.0.100";

Server.on('listening', () => {
    console.log("server running!");
    Server.setBroadcast(true); // 允许广播
    Server.setMulticastTTL(128); // 设置TTL
    Server.addMembership(multi_ip); // 添加组播
    // 周期发送
    setInterval(() => {
        Server.send("Hello,World!", 8001, multi_ip)
        Server.send("Hello,World!", 8002, multi_ip)

    }, 1500)
});

Server.on('message', (msg, info) => {
    console.log(msg.toString(), info)
})

Server.on('error', (err) => {
    console.log(err)
})

Server.bind()
