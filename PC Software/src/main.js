const { write } = require("original-fs");
const { SerialPort, ReadlineParser } = require("serialport");

const keypadBox = document.getElementById("kpb");

const keyNameInput = document.getElementById("keyName");
const keyStrokeInput = document.getElementById("keyStroke");
const textInput = document.getElementById("inputText");
const saveButton = document.getElementById("save");

const warnBox = document.getElementById("warn-box");

const portElement = document.getElementById("portAndPath");

const overlay = document.getElementById("ovrly");

const prg_cont = document.getElementById("prg");

let key_insert = false;

let btnId;

const strokes = [""];

let i = 0;

const RP2040_ZERO_VENDOR_ID = "2E8A";

let interval;

let char = "";

SerialPort.list().then(boards => {
    console.log(boards);

    if (boards[0].vendorId == RP2040_ZERO_VENDOR_ID) {
        
        const port = new SerialPort({
            path: boards[0].path,
            baudRate: 9600,
            dataBits: 8,
            parity: "none",
            stopBits: 1,
            autoOpen: true
        });
        
        const parser = new ReadlineParser({ delimiter: "\r\n" });
        port.pipe(parser);
        
        console.log(`${port.path} is open at baud rate: ${port.baudRate}`);
        
        portElement.innerHTML = `RP2040 - ${port.path}`;

        const toggleInsertTrue = () => {
            key_insert = true;
            document.body.classList.replace("key_insert_false", "key_insert_true");
        }
        
        const toggleInsertFalse = () => {
            key_insert = false;
            document.body.classList.replace("key_insert_true", "key_insert_false");
            emptyStrokes();
        }
        
        const toggleInsert = (button) => {
            if (button.id != "" && !key_insert) {
                toggleInsertTrue();
            } else if (button.id != "" && key_insert) {
                toggleInsertFalse();
            }
        }
        
        const emptyStrokes = () => {
            for (i; i >= 0; i--) {
                strokes[i] = "";
            }
            char = "";
            i = 0;
        
            console.log(`strokes are empty: ${strokes[0]} + ${strokes[1]} + ${strokes[2]} + ${strokes[3]}`);
        
            keyNameInput.value = "";
            keyStrokeInput.value = "";
            textInput.value = "";
            keyStrokeInput.classList.remove("warning");
            warnBox.classList.replace("warning-box-true", "warning-box-false");
        }

        let checkStroke = (stroke) => {
            if (stroke == "Control") {
                return "128";
            } else if (stroke == "Alt") {
                return "130";
            } else if (stroke == "Shift") {
                return "129";
            } else if (stroke == "" || stroke == undefined) {
                return "000";
            } else if (stroke == "F4") {
                return "197";
            } else if (stroke == "Meta") {
                return "135";
            } else if (stroke == "Enter") {
                return "176";
            } 
            else {
                if (stroke.charCodeAt(0) < 100) {
                    return `0${stroke.charCodeAt(0)}`;
                } else return `${stroke.charCodeAt(0)}`;
            } 
        }

        async function sendStrokes() {
            for (let i = 0; i < 4; i++) {
                if (i == 0) {
                    char += `f${checkStroke(strokes[i])}`;
                } else if (i == 1) {
                    char += `s${checkStroke(strokes[i])}`;
                } else if (i == 2) {
                    char += `t${checkStroke(strokes[i])}`;
                } else if (i == 3) {
                    char += `r${checkStroke(strokes[i])}`;
                }
            }
            console.log("Strokes sent");
            return 1;
        } 
        
        keypadBox.addEventListener("click", e => {
            let button = e.target;
            btnId = button.id;
            toggleInsert(button);
        });
        
        window.addEventListener("keydown", e => {
            if (e.key == "Escape" && key_insert) toggleInsertFalse();
        })
        
        keyStrokeInput.addEventListener("keyup", e => {
            if (i < 4) {
                if (keyStrokeInput.value == "") keyStrokeInput.value = e.key;
                else {
                    if (e.key != "Control" && e.key != "Alt" && e.key != "Shift") keyStrokeInput.value += ` + ${e.key.toUpperCase()}`;
                    else keyStrokeInput.value += ` + ${e.key}`;
                }
                strokes[i] = e.key;
                /*
                e.key == "Control" ? char += "128" 
                : e.key == "Alt" ? char += "130" 
                : e.key == "Shift" ? char += "129" 
                : e.key == "" ? char += "000"
                : char += `${e.key.charCodeAt(0)}`; */
                i++;
            } else {
                console.log(`Strokes are full : ${strokes[0]} + ${strokes[1]} + ${strokes[2]} + ${strokes[3]}`);
                keyStrokeInput.classList.add("warning");
                warnBox.classList.replace("warning-box-false", "warning-box-true");
                return;
            }
        })
        
        keyStrokeInput.addEventListener("dblclick", emptyStrokes);
        
        saveButton.addEventListener("click", () => {
            if (keyNameInput.value == "" && keyStrokeInput.value == "" && textInput.value == "") toggleInsertFalse();
            else {
                console.log(`Key Name: ${keyNameInput.value} | Key Stroke: ${keyStrokeInput.value} | Text: ${textInput.value} | Button ID: ${btnId}`);
                document.getElementById(btnId).innerHTML = keyNameInput.value[0];

                keyStrokeInput.value == "" ? port.write("0\n") : sendStrokes().then(value => {
                    if (value == 1) {
                        console.log(value);
                        textInput.value != "" ? char += "txt" + textInput.value + "~btn" + btnId : char += "txt000" + "~btn" + btnId;
                        console.log(char);
                        port.write(`${char}\n`);
                        toggleInsertFalse();
                    } else {
                        console.error("Data Send Unsuccessfully!");
                    }
                });

                prg_cont.classList.replace("prog_cont_false", "prog_cont");
                prg_bar.classList.replace("progress-container-false", "progress-container");
                overlay.classList.replace("overlay-0", "overlay-1");

                interval = setInterval(growProgress, t);
            }
        })

        parser.on("data", data => {
            console.log(`data: ${data}`);
            if (data == "l1") {
                keypadBox.classList.replace("keypad-box-r", "keypad-box-g");
            } else if (data == "l2") {
                keypadBox.classList.replace("keypad-box-g", "keypad-box-b");
            } else if (data == "l0") {
                keypadBox.classList.replace("keypad-box-b", "keypad-box-r");
            }
        });
    }
});

const progres = document.getElementById("prgs_value");
const progress_h3 = document.getElementById("bar_prgs");

const progress_h1 = document.getElementById("prgs");

const uplad_status = document.querySelector("#stats");
const prg_bar = document.querySelector("#prgbar");

let b = 1;
let t = 100;

function growProgress() {
    if (b < 100) {
        if (b < 20) b += 1;
        else if (b >= 20 && b < 50) b += 5;
        else if (b >= 50 && b < 90) b += 10;
        else if (b >= 90) b += 1;
        progres.style.width = `${b}%`;
        progress_h1.innerText = `${b}%`;
        progress_h3.innerText = `${b}%`;
    } else {
        clearInterval(interval);
        setTimeout(() => {
            uplad_status.classList.replace("upload-status-false", "upload-status");
            prg_bar.classList.replace("progress-container", "progress-container-false");
        }, 1000);

        setTimeout(() => {
            uplad_status.classList.replace("upload-status", "upload-status-false");
            prg_cont.classList.replace("prog_cont", "prog_cont_false");
            overlay.classList.replace("overlay-1", "overlay-0");
        }, 2000);
        
        console.log("Cleared Interval");

        b = 1;
    }
}


