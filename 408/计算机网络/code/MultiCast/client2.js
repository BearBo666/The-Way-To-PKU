const dgram = require("dgram");
const Client = dgram.createSocket("udp4");

// 组播地址
const multi_ip = "225.0.0.100";

Client.on('listening', () => {
    console.log("client running!");
    Client.setBroadcast(true); // 允许广播
    Client.setMulticastTTL(128); // 设置TTL
    Client.addMembership(multi_ip); // 添加组播成员
})

Client.on('message', (msg, info) => {
    console.log(msg.toString(), info)
    // 响应
    Client.send("Hi,I am client2!", info.port, info.address)
})

Client.bind(8002)