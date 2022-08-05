
u32 setbit(u32 n,u32 bit);
{
	return n=(x|(1<<bit));
}
u32 clearbit(u32 n,u32 bit);
{
	return n=(x&(~(1<<bit)));
}
u32 togglebit(u32 n,u32 bit);
{
	return  n=(x^(1<<bit));
}
u32 readbit(u32 n,u32 bit);
{
	return n=(1&(x>>bit));
}