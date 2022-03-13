/* let input = document.getElementByID('sell');
            input.addEventListener("change", async function() {
                let response = await fetch("https://cloud.iexapis.com/stable/stock/${input}/quote?token=pk_68b782ab6d7b4d3caac3671fc5a1c489");
                let stock = await response.json();
                let html = "<li>" stock.latestPrice "</li>";
                document.querySelector('ul').innerHTML = html;
            });
*/
document.getElementById('stock').addEventListener('change', function() {
    console.log('You selected: ', this.value);
  });
