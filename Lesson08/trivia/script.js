document.addEventListener("DOMContentLoaded", function() {
  let checkResult1 = document.querySelector('p#check-result1');
  let checkResult2 = document.querySelector('p#check-result2');
  let inputBox = document.querySelector('input#input-box');

  function refresh() {
    document.querySelectorAll('button.option').forEach(button => {
      button.style.backgroundColor = '#d9edff';
    });
    checkResult1.innerText = '';
    checkResult2.innerText = '';
    inputBox.style.backgroundColor = '#ffffff';
    inputBox.value = '';
  }

  document.querySelectorAll('button.option').forEach(button => {

    const ANSWER = 'SQL';
    button.addEventListener('click', function (event) {
      event.preventDefault();
      refresh();
      if (button.innerText === ANSWER) {
        button.style.backgroundColor = '#00ff00';
        checkResult1.innerHTML = 'Correct!';
      } else {
        button.style.backgroundColor = '#ff0000';
        checkResult1.innerHTML = 'Incorrect!';
      }
    });
  });

  document.querySelector('button.submit').addEventListener('click', function (event) {
    event.preventDefault();

    const ANSWER = 'Javascript';
    if (inputBox.value === ANSWER) {
      checkResult2.innerText = 'Correct!';
      inputBox.style.backgroundColor = '#00ff00';
    } else {
      checkResult2.innerText = 'Incorrect!';
      inputBox.style.backgroundColor = '#ff0000';
    }
  });

  document.querySelector('input#input-box').addEventListener('click', function (event) {
    event.preventDefault();
    refresh();
  })
});