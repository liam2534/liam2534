const BAUD_RATE = 9600; // This should match the baud rate in your Arduino sketch

let port, connectBtn; // Declare global variables

let txtColor = "idk_yet";

function setup() {
  setupSerial(); // Run our serial setup function (below)

  // Create a canvas that is the size of our browser window.
  // windowWidth and windowHeight are p5 variables
  createCanvas(windowWidth, windowHeight);

  // p5 text settings. BOLD and CENTER are constants provided by p5.
  // See the "Typography" section in the p5 reference: https://p5js.org/reference/
  textFont("system-ui", 50);
  textStyle(BOLD);
  textAlign(CENTER, CENTER);
  
}

function draw() {
  const portIsOpen = checkPort();
  if (!portIsOpen) return;

  let str = port.readUntil("\n");
  if (str.length == 0) return; 

  let valArray = str.trim().split(",");
  
  if(valArray[0] <= 600){
    background("red");
  } else{
    background("black");
  }

  if(valArray[1] <= 600){
    txtColor = "white";
  } else {
    txtColor = "gold";
  }

  if(mouseIsPressed){
    fill(txtColor);
    text("YOU ARE NOW PRESSING THE MOUSE, AND THE LED IS ON!", windowWidth / 2, windowHeight / 2);
    port.write(0);
  } else{
    fill(txtColor);
    text("PRESS LEFT MOUSE BUTTON TO TOGGLE LED", windowWidth / 2, windowHeight / 2);
    port.write(1);
  }

}

// Three helper functions for managing the serial connection.

function setupSerial() {
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
