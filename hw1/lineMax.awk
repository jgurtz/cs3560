BEGIN {
    max = 0
}
{
    for (i=1; i<=NF; i++) {

        $i > max ? max = $i : max = max
    }
    print max
    max = 0
}
