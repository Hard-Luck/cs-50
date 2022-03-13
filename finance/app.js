

let input = document.querySelector('input');
            input.addEventListener('input', async function() {
                let response = await fetch("https://cloud.iexapis.com/stable/stock/{}/quote?token=pk_68b782ab6d7b4d3caac3671fc5a1c489" + input.value);
                let shows = await response.json();
                let html = '';
                for (let id in shows) {
                    let title = shows[id].title.replace('<', '&lt;').replace('&', '&amp;');
                    html += '<li>' + title + '</li>';
                }
                document.querySelector('ul').innerHTML = html;
            });