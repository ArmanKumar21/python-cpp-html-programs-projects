alert("Made with love by Shreyash");
var O = document.getElementById("E");
var B = document.getElementById("empty");
B.onclick = function() {
    return location.href = "Instructions.html";
}

function vibrate() {
    navigator.vibrate(1000);
}

function getHistory() {
    return document.getElementById("historyvalue").innerText;
}

function printHistory(num) {
    document.getElementById("historyvalue").innerText = num;
}

function printOutput(num) {
    if (num == 0)
        document.getElementById("output-value").innerText = num;
    else
        document.getElementById("output-value").innerText = getFormattedvalue(num);
}

function getOutput() {
    return document.getElementById("output-value").innerText;
}

function getFormattedvalue(num) {
    if (num == "-") {
        return "";
    }
    var n = Number(num);
    var value = n.toLocaleString("en");
    return value;
}

function RNF(num) {
    return Number(num.replace(/,/g, ''));
}
var operator = document.getElementsByClassName("operator");
for (var i = 0; i < operator.length; i++) {
    operator[i].addEventListener('click', function() {
        if (this.id == "clear") {
            printHistory("");
            printOutput("");
        } else if (this.id == "backspace") {
            let output = RNF(getOutput()).toString();
            if (output) {
                output = output.substr(0, output.length - 1);
                printOutput(output);
            }
        } else {
            let output = getOutput();
            let history = getHistory();
            if (output == "" && history != "") {
                if (isNaN(history[history.length - 1])) {
                    history = history.substr(0, history.length - 1);
                }
            }
            if (output != "" || history != "") {
                output = output == "" ?
                    output : RNF(output);
                history = history + output;
                if (this.id == "E") {
                    let result = eval(history);
                    printOutput(result);
                    printHistory("");
                } else {
                    history = history + this.id;
                    printHistory(history);
                    printOutput("");
                }
            }
        }
    });
}
var number = document.getElementsByClassName("number");
for (var i = 0; i < number.length; i++) {
    number[i].addEventListener('click', function() {
        var output = RNF(getOutput());
        if (output != NaN) {
            output = output + this.id;
            printOutput(output);
        }
    });
}
var button = document.getElementsByTagName("button");
for (let i = 0; i < button.length; i++) {
    try {
        button[i].addEventListener('click', vibrate());
        throw e;
    } catch (e) {
        console.log("Tap on screen");
    }
}
var mic = document.getElementById("mic");
mic.onclick = function() {
    mic.classList.add("record");
    var recognition = new(window.SpeechRecognition || window.webkitSpeechRecognition || window.mozSpeechRecognition || window.msSpeechRecognition)();
    recognition.lang = 'en-US';
    recognition.start();
    operations = {
        "plus": "+",
        "minus": "-",
        "multiply": "*",
        "divide": "/",
        "divided by": "/",
        "remainder": "%",
        "modulus": "%",
        "into": "*",
        "multiply by": "*",
        "add": "+",
        "slash":"/",
        "subtract": "-"
    }
    recognition.onresult = function(event) {
        var input = event.results[0][0].transcript;
        for (property in operations) {
            input = input.replace(property, operations[property]);
        }
        document.getElementById("output-value").innerText = input;
        setTimeout(function() {
            evaluate(input);
        }, 2000);
        mic.classList.remove("record");
    }
}

function evaluate(input) {
    try {
        var result = eval(input);
        document.getElementById("output-value").innerText = result;
    } catch (e) {
        console.log(e);
        document.getElementById("output-value").innerText = "";
    }
}