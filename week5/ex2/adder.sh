if { set -C; 2>/dev/null >~/filelocker.lock; }; then
         trap "rm -f ~/filelocker.lock" EXIT;
else
         echo "file is not accessible";
         exit;
fi

last_line="$(tail --lines=1 file)";
echo $((last_line+1))>>file;
exit;
