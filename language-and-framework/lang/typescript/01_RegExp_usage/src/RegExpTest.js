class RegExpTest {

    simpleCheck() {
        let re = /cgp-\w+/;
        let res = re.test('cgp-site-currency');
        console.log(`The check is ${res}`);
    }

}

export default RegExpTest;
