#!/bin/bash

# Usage: bash run.sh file=<subdirectory>

# Parse arguments
for arg in "$@"
do
    case $arg in
        file=*)
        SUBDIR="${arg#*=}"
        shift
        ;;
        *)
        echo "Invalid argument: ${arg}"
        exit 1
        ;;
    esac
done

# Set default values if not provided
SUBDIR=${SUBDIR:-.}
REPORT_FILE="report.html"

# Check if pytest is installed
if ! command -v pytest &> /dev/null
then
    echo "pytest could not be found, please install it."
    exit 1
fi

# Determine the test directory
if [ "$SUBDIR" != "." ]; then
    TEST_DIR=$(find . -type d -name "$SUBDIR" -print -quit)
    if [ -z "$TEST_DIR" ]; then
        echo "Test directory for subdirectory '$SUBDIR' not found."
        exit 1
    fi
else
    TEST_DIR="."
fi

# Run pytest with the specified test directory and generate an HTML report
pytest --html="$REPORT_FILE" --self-contained-html "$TEST_DIR"

echo "Test report generated: $REPORT_FILE"
