uses math;
var
    dx:array[1..4] of longint=(0,1,0,-1);
    dy:array[1..4] of longint=(1,0,-1,0);
    a:array[0..1000,0..1000] of char;
    dp:array[0..1000,0..1000] of longint;
    i,j,n,m,d,res:longint;
    s:ansistring;
procedure dq(x,y:longint);
  var u,v,k:longint;
    begin
      inc(d);
      dp[x,y]:=1;
        for k:=1 to 4 do
          begin
              u := x+dx[k];
              v := y+dy[k];
              if (u>=1)and(u<=n)and(v>=1)and(v<=m)and(a[u,v]>=a[x,y])and(dp[u,v]=0) then dq(u,v);
          end;  
          res := max(res,d);
          dp[x,y]:=0;
          dec(d);
      end;      
begin
    readln(n,m);
    for i:=1 to n do
      begin
          readln(s);
          for j:=1 to m do
            a[i,j]:=s[j];
      end;
    res := 0;
    for i:=1 to n do
      for j:=1 to m do
        begin
            d := 0;
            dq(i,j);
        end;
    write(res);
end.
    