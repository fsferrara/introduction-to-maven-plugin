const sum = require('../../src/sum');

const {IntegrationServer} = require('../integration-support/integration-server');
const server = new IntegrationServer(sum);

const request = require("supertest");

describe('sum component integration tests', () => {
    test('adds 2 + 2 to equal 4', async () => {

        server.start(2,2);

        const response = await request("http://localhost:3000")
            .get('/');

        expect(response.statusCode).toBe(200);
        expect(response.body.error).toBe(undefined);
        expect(response.text).toBe("4");

        server.stop();
    });
});
