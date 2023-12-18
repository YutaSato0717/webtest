let counter = 0;
const display = document.getElementById('display');
const addButton = document.getElementById('add');
const subButton = document.getElementById('sub');
const mulButton = document.getElementById('mul');

function updateDisplay() {
  display.textContent = counter;
}

function increment() {
  if (counter < 100) {
    counter += 1;
    updateDisplay();
  }
}

function decrement() {
  if (counter > 0) {
    counter -= 1;
    updateDisplay();
  }
}

function multiply() {
  if (counter <= 100 / 2) {
    counter *= 2;
    updateDisplay();
  }
}

addButton.addEventListener('click', increment);
subButton.addEventListener('click', decrement);
mulButton.addEventListener('click', multiply);
