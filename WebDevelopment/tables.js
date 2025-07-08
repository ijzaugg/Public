$("document").ready(() => {
  if (!(color_rows === -1)) {
    createColorTable(color_rows);
  }
  if (!(row_col === -1)) {
    createSquareTable(row_col);
  }
});

let selectedColor = ""; // Global variable to store selected color
let selectedColors = []; // Global array to keep track of selected colors
let colorCellsMap = {}; // Object to map selected cells for each color

function createColorTable(color_rows) {
  let colorTable = document.getElementById("colorTable");
  colorTable.innerHTML = "";
  let table = document.createElement("table");

  let options = [
    "Red",
    "Orange",
    "Yellow",
    "Green",
    "Teal",
    "Blue",
    "Purple",
    "Grey",
    "Brown",
    "Black",
  ];

  for (let i = 0; i < color_rows; i++) {
    let row = document.createElement("tr");
    let leftColumn = document.createElement("td");

    let select = document.createElement("select");
    let emptyOption = document.createElement("option");
    emptyOption.textContent = "";
    select.appendChild(emptyOption);

    options.forEach((option) => {
      let optionSelect = document.createElement("option");
      optionSelect.textContent = option;
      select.appendChild(optionSelect);
    });

    select.addEventListener("change", (event) => {
      let selectedRowColor = event.target.value;
      if (selectedColors.includes(selectedRowColor)) {
        alert("Error: This color has already been selected.");
        select.value = "";
      } else {
        let oldColor = selectedColors[i];
        let radioBtn = row.querySelector("input");
        if (radioBtn.classList.length > 0) {
          let prevColor = selectedColors[i];
          radioBtn.classList.replace(prevColor, selectedRowColor);
        } else {
          radioBtn.classList.add(selectedRowColor);
        }
        selectedColors[i] = selectedRowColor;
        selectedColor = selectedRowColor;
        updateSquareColors(oldColor);
        updateSelectedCellsList(selectedRowColor); // Update selected cells list
      }
    });

    var radio = document.createElement("input");
    radio.type = "radio";
    radio.name = "colorSelector";
    if (i == 0) {
      radio.checked = true;
      selectedColor = options[0];
    }

    radio.addEventListener("change", () => {
      let dropdown = row.querySelector("select");
      selectedColor = dropdown.value;
    });

    leftColumn.appendChild(radio);
    leftColumn.appendChild(select);

    let rightColumn = document.createElement("td");

    row.appendChild(leftColumn);
    row.appendChild(rightColumn);

    table.appendChild(row);
  }

  colorTable.appendChild(table);
}

function createSquareTable(rowscols) {
  var squareTable = document.getElementById("squareTable");
  squareTable.innerHTML = "";

  var table = document.createElement("table");

  for (var i = 0; i <= rowscols; i++) {
    var row = document.createElement("tr");

    for (var j = 0; j <= rowscols; j++) {
      var col = document.createElement("td");

      if (i == 0 && j == 0) {
        col.textContent = "";
      } else if (i == 0 && j > 0) {
        col.textContent = String.fromCharCode(64 + j);
      } else if (j == 0 && i > 0) {
        col.textContent = i;
      } else if (i > 0 && j > 0) {
        col.setAttribute("id", String.fromCharCode(64 + j) + "_" + i);
        col.addEventListener("click", styleClickedSquare);
      }
      row.appendChild(col);
    }
    table.appendChild(row);
  }

  squareTable.appendChild(table);
}

function styleClickedSquare() {
  var coloredSquare = this;
  var radioButtons = document.getElementsByName("colorSelector");

  // Find the selected radio button
  var selectedRadioButton;
  for (var i = 0; i < radioButtons.length; i++) {
    if (radioButtons[i].checked) {
      selectedRadioButton = radioButtons[i];
      break;
    }
  }

  // Get the selected color from the selected radio button
  var selectedColor = selectedRadioButton.nextSibling.value;

  if (coloredSquare.classList.length > 0) {
    var prevColor = coloredSquare.classList.item(0);
    coloredSquare.classList.replace(prevColor, selectedColor);
  } else {
    coloredSquare.classList.add(selectedColor);
  }

  coloredSquare.style.backgroundColor = selectedColor;
  updateSelectedCellsList(selectedColor); // Update selected cells list
}


function updateSquareColors(oldColor) {
  var cells = document.querySelectorAll("#squareTable td");

  cells.forEach(function(cell) {
    if (cell.classList.contains(oldColor)) {
      cell.classList.remove(oldColor);
      cell.classList.add(selectedColor);
      cell.style.backgroundColor = selectedColor;
    }
  });
}

function updateSelectedCellsList(color) {
  // Get the right-hand column of the color table
  var rightColumn = document.querySelectorAll("#colorTable td:nth-child(2)");
  // Find all cells with the selected color
  var colorIndex = selectedColors.indexOf(color);
  var cell = rightColumn[colorIndex];

  // All cells that have the current color
  var cells = document.querySelectorAll("#squareTable td." + color);
  var cellIDs = Array.from(cells).map((cell) => cell.getAttribute("id"));

  // All cell id's are formatted as A-1, B-2, etc.
  // List each with a comma seperator
  cell.textContent = cellIDs.join(", ");

  // Remove IDs from previous color's list
  for (var i = 0; i < selectedColors.length; i++) {
    if (selectedColors[i] !== color) {
      var prevColorCells = document.querySelectorAll(
        "#squareTable td." + selectedColors[i]
      );
      var prevCellIDs = Array.from(prevColorCells).map((cell) =>
        cell.getAttribute("id")
      );
      var prevCell = rightColumn[i];
      prevCell.textContent = prevCellIDs.join(", ");
    }
  }
}