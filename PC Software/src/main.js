const { SerialPort, ReadlineParser } = require("serialport");

const keypadBox = document.querySelector(".keypad-box");

const keyNameInput = document.getElementById("keyName");
const keyStrokeInput = document.getElementById("keyStroke");
const textInput = document.getElementById("inputText");
const saveButton = document.getElementById("save");

const warnBox = document.getElementById("warn-box");

const portElement = document.getElementById("portAndPath");

let key_insert = false;

let btnId;

const strokes = [];

let i = 0;

const RP2040_ZERO_VENDOR_ID = "2E8A";

SerialPort.list().then(boards => {
    console.log(boards[0]);

    if (boards[0].vendorId == RP2040_ZERO_VENDOR_ID) {
        portElement.innerHTML = `RP2040 - ${boards[0].path}`;

        const port = new SerialPort({
            path: boards[0].path,
            baudRate: 9600,
            dataBits: 8,
            parity: "none",
            stopBits: 1,
            autoOpen: false
        });

        const parser = new ReadlineParser({ delimiter: "\r\n" });
        port.pipe(parser);

        console.log(`${port.path} is open at baud rate: ${port.baudRate}`);

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
        
            i = 0;
        
            console.log(`strokes are empty: ${strokes[0]} + ${strokes[1]} + ${strokes[2]}`);
        
            keyNameInput.value = "";
            keyStrokeInput.value = "";
            textInput.value = "";
            keyStrokeInput.classList.remove("warning");
            warnBox.classList.replace("warning-box-true", "warning-box-false");
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
            if (i < 3) {
                if (keyStrokeInput.value == "") keyStrokeInput.value = e.key;
                else {
                    if (e.key != "Control" && e.key != "Alt" && e.key != "Shift") keyStrokeInput.value += ` + ${e.key.toUpperCase()}`;
                    else keyStrokeInput.value += ` + ${e.key}`;
                }
                strokes[i] = e.key;
                i++;
            } else {
                console.log(`Strokes are full : ${strokes[0]} + ${strokes[1]} + ${strokes[2]}`);
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
                
                //port.write(`ks:${keyStrokeInput.value}\n`);
                port.write(`txt:${textInput.value}\n`);
                //port.write(`btn:${btnId}\n`);

                keyNameInput.value = "";
                keyStrokeInput.value = "";
                textInput.value = "";
            
                toggleInsertFalse();
            }
        })

        parser.on("data", data => {
            console.log(`data: ${data}`);
        });
    }
});

