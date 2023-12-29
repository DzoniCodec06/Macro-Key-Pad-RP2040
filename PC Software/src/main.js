const keypadBox = document.querySelector(".keypad-box");

const keyNameInput = document.getElementById("keyName");
const keyStrokeInput = document.getElementById("keyStroke");
const textInput = document.getElementById("inputText");
const saveButton = document.getElementById("save");

let key_insert = false;

let btnId;

const strokes = []

let i = 0;

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
        return;
    }

})

saveButton.addEventListener("click", () => {
    if (keyNameInput.value == "" && keyStrokeInput.value == "" && textInput.value == "") toggleInsertFalse();
    else {
        console.log(`Key Name: ${keyNameInput.value} | Key Stroke: ${keyStrokeInput.value} | Text: ${textInput.value} | Button ID: ${btnId}`);
        keyNameInput.value = "";
        keyStrokeInput.value = "";
        textInput.value = "";
    
        toggleInsertFalse();
    }
})
