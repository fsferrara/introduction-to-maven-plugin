const express = require('express')
const app = express();
const port = 3000;

class IntegrationServer {

    /**
     * Initialize the integrtion server.
     * @param sut software under test function that takes two parameters.
     */
    constructor(sut) {
        this.sut = sut;
    }

    /**
     * Start the integration server
     * @param a first sut parameter
     * @param b second sut parameter
     */
    start(a, b) {
        app.get('/', (req, res) => {
            console.log(`Serving response for ${a} and ${b}`);
            res.send(`${this.sut(a,b)}`);
        })

        this.server = app.listen(port, () => {
            console.log(`IntegrationServer listening on port ${port}`);
        })
    }

    stop() {
        this.server.close();
    }
}

module.exports = {
    IntegrationServer
}
