BEGIN {
    sum = 0
}
{
    sum += $NR
}
END {
    print sum
}
