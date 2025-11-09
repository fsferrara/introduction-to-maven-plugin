import Adder from '../lib';

test("Adds two numbers", () => {
    const adder = new Adder();
    const actual = adder.add(1,1);
    expect(actual).toBe(2);
});
