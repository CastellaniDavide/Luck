{ constraints }
const
    MAXK = 200;
    MAXC = 10000;

{ input data }
var
    K, C, i : longint;
    L       : array[0..MAXK-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(K, C);
    for i:=0 to K-1 do
        readln(L[i]);

    { insert your code here }

    writeln(42); { change 42 with actual answer }
end.
