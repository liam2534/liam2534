//baud rate matches arduino
const BAUD_RATE = 9600;

//global variables to be used later for the port and connect button
let port, connectBtn;

//variable for txt color to be determined later
let txtColor = "idk_yet";

//runs once
function setup() {
  // Run our serial setup function (below)
  setupSerial(); 

  // Create a canvas that is the size of our browser window.
  // windowWidth and windowHeight are p5 variables
  createCanvas(windowWidth, windowHeight);

  // p5 text settings. BOLD and CENTER are constants provided by p5.
  // See the "Typography" section in the p5 reference: https://p5js.org/reference/
  textFont("system-ui", 50);
  //makes text bold
  textStyle(BOLD);
  //makes text in the center of the screen
  textAlign(CENTER, CENTER);
  
}

//draw function runs repeatedly
function draw() {
  //makes a const portIsOpen value equal to checkPort
  const portIsOpen = checkPort();
  //checks if port is open, if not, returns.
  if (!portIsOpen) return;

  //makes a string of the whole line from the serial monitor
  let str = port.readUntil("\n");
  //if string length is empty, returns.
  if (str.length == 0) return; 

  //makes an array from the comma separated values from the serial monitor from the arduino
  let valArray = str.trim().split(",");
  
  //checks if the first value in the array is <= 600
  if(Number(valArray[0]) <= 600){
    //if yes, makes background color red
    background("red");
    //else statement if valArray[0] fails first check
  } else{
    //makes background color black
    background("black");
  }

  //check for value of valArray[1]
  if(Number(valArray[1]) <= 600){
    //if the number is <= 600, text color is white
    txtColor = "white";
    //else if first if fails
  } else {
    //makes text color gold if first check fails
    txtColor = "gold";
  }

  //check for if mouse is pressed
  if(mouseIsPressed){
    //makes the text in center (see text line in this if branch) correspond to txtColor
    fill(txtColor);
    //if mouseIsPressed, displays the bottom message in the center of screen
    text("YOU ARE NOW PRESSING THE MOUSE, AND THE LED IS ON!", windowWidth / 2, windowHeight / 2);
    //writes 0 to the port, which is used by the arduino to turn light on
    port.write(0);
    //else branch for when mouse is not pressed
  } else{
    //makes text below correspond to txtColor
    fill(txtColor);
    //displays this text in the center of the screen
    text("PRESS LEFT MOUSE BUTTON TO TOGGLE LED", windowWidth / 2, windowHeight / 2);
    //writes 1 to port, used by arduino to toggle the light off.
    port.write(1);
  }

}

// Three helper functions for managing the serial connection.

//setup port to read in the serial monitor
function setupSerial() {
  //makes port read from serial monitor
  port = createSerial();

  // Check to see if there are any ports we have used previously
  let usedPorts = usedSerialPorts();
  if (usedPorts.length > 0) {
    // If there are ports we've used, open the first one
    port.open(usedPorts[0], BAUD_RATE);
  }

  // create a connect button
  connectBtn = createButton("Connect to Arduino");
  connectBtn.position(5, 5); // Position the button in the top left of the screen.
  connectBtn.mouseClicked(onConnectButtonClicked); // When the button is clicked, run the onConnectButtonClicked function
}

function checkPort() {
  if (!port.opened()) {
    // If the port is not open, change button text
    connectBtn.html("Connect to Arduino");
    // Set background to gray
    background("gray");
    return false;
  } else {
    // Otherwise we are connected
    connectBtn.html("Disconnect");
    return true;
  }
}

function onConnectButtonClicked() {
  // When the connect button is clicked
  if (!port.opened()) {
    // If the port is not opened, we open it
    port.open(BAUD_RATE);
  } else {
    // Otherwise, we close it!
    port.close();
  }
}