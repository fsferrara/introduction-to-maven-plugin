describe('example of only associated to a single test', () => {

    test.only('this will be the only test that runs', () => {
        debugger;
        expect(true).toBe(true);
    });

    test('this test will not run', () => {
        expect('A').toBe('B');
    });

});
