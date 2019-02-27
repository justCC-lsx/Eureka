package main

import (
	"encoding/json"
	"fmt"
)

type Packet struct {
	Cmd  string      `json:"cmd"`
	Data interface{} `json:"data"`
}

type Control struct {
	Code int    `json:"code"`
	Msg  string `json:"msg"`
}

type Message struct {
	Msg string `json:"msg"`
}

func testSerialization() {
	cp := &Packet{
		Cmd: "ctrl",
		Data: &Control{
			Code: 0xDEADBEEF,
			Msg:  "heartbeat",
		},
	}

	raw, err := json.Marshal(cp)
	if err != nil {
		panic(err)
	}

	fmt.Println(string(raw))

	mp := &Packet{
		Cmd: "msg",
		Data: &Message{
			Msg: "Echo",
		},
	}

	raw, err = json.Marshal(mp)
	if err != nil {
		panic(err)
	}

	fmt.Println(string(raw))
}

func testDeserialization() {
	var err error

	p := &Packet{}
	cpJson := `{"cmd":"ctrl","data":{"code":3735928559,"msg":"heartbeat"}}`
	err = json.Unmarshal([]byte(cpJson), p)
	if err != nil {
		panic(err)
	}
	printPacket(p)

	mpJson := `{"cmd":"msg","data":{"msg":"Echo"}}`
	err = json.Unmarshal([]byte(mpJson), p)
	if err != nil {
		panic(err)
	}
	printPacket(p)
}

func printPacket(packet *Packet) {
	data := packet.Data.(map[string]interface{})

	switch packet.Cmd {
	case "ctrl":
		fmt.Printf("Control packet\ncode=%d\nmsg=%s\n", data["code"], data["msg"])
		break
	case "msg":
		fmt.Printf("Message packet\nmsg=%s\n", data["msg"])
		break
	default:
		panic("unreachable")
	}
}

func main() {
	testSerialization()
	testDeserialization()
}
