//Interactions for DB

const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('database.sqlite');


//add function
function add(id, Name, hex){
    command = `INSERT INTO colors VALUES (" ${id} "," ${Name} "," ${hex} ")`;
    db.run(command);
}

//delete functions
function removeByID(id){
    command = `DELETE FROM colors WHERE id = "${id} "`;
    db.run(command);
}
function removeByName(name){
    command = `DELETE FROM colors WHERE Name = "${name} "`;
    db.run(command);
}
function removeByHex(hex){
    command = `DELETE FROM colors WHERE hexValue = "${hex} "`;
    db.run(command);
}

//search function(returns true if found, false if not found)
function findID(id){
    return db.run(`"${id} " IN colors`);
}


//testing 
/*
add(1,"red","#FF0000");
add(2,"orange","##ffa500");
add(3, "yellow", "#ffbf00");
add(4,"green","#00ff00");
add(5,"teal","#008080");
add(6, "blue", "#0000ff");
add(7,"purple","#9400d3");
add(8,"pink","#ff007f");
add(9, "black", "#000000");
add(10, "white", "#FFFFFF");
*/
removeByID(13);
removeByID(14);
removeByID(15);

db.close();