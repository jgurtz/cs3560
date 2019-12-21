BEGIN {
    sum = 0
}
{
    sum += $(NF-NR+1)
    
}
END {
    print sum
}
