document.addEventListener("DOMContentLoaded", function() {
    let logo = document.getElementById("logo");
    logo.addEventListener("mouseover", function() {
        const node = document.createElement("h1")
        const textnode = document.createTextNode("WELCOME!");
        node.appendChild(textnode);
        document.getElementById("title").appendChild(node);
    })
});