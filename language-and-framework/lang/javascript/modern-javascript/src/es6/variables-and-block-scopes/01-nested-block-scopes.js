/*
Is this a valid javascript expression?

    {{{}}}

Yes. Those are three nested block scopes.
*/

{
    console.log('-- first block scope');
    {
        console.log('---- second block scope');
        {
            console.log('------ third block scope');
        }
    }
}