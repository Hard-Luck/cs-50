let input = document.querySelector('sell');
            input.addEventListener('sell', async function() {
                let response = await fetch("https://cloud.iexapis.com/stable/stock/${input}/quote?token=pk_68b782ab6d7b4d3caac3671fc5a1c489");
                let shows = await response.json();
                let html = '';
                for (let id in shows) {
                }
            });