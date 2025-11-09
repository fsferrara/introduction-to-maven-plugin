const GqlEngine = require('../src/gql-engine');

test('load and run the engine', () => {
    const eng = new GqlEngine();
    eng.execute('{ hello }');
});
