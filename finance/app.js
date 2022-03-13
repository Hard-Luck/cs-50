

let input = document.querySelector('input');
            input.addEventListener('input', async function() {
                let response = await fetch("https://cloud.iexapis.com/?filter=symbol,volume,lastSalePrice" + input.value);
                let shows = await response.json();
                let html = '';
                for (let id in shows) {
                    let title = shows[id].title.replace('<', '&lt;').replace('&', '&amp;');
                    html += '<li>' + title + '</li>';
                }
                document.querySelector('ul').innerHTML = html;
            });