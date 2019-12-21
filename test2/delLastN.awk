BEGIN {
    # n is number of lines to delete from end, defaults to 2
    # adjust by running like (del last 5 lines): awk -v n=5
    ( length(n) > 0 ) ? n=n : n = 2
}
n <= 0 { # special case; just emulate cat
    print $0
    next
}
NR > n {
    printf ( length(lines[0]) > 0 ) ? lines[0] : "\0"
}
{
    for (i=0; i<n-1; i++) {
        lines[i] = lines[i+1]
    }
    lines[n-1] = $0 
}
