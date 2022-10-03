fn replace_char(input :&str) -> String {
    return input.replace("&", "&amp").replace("<", "&lt").replace(">", "&gt");
}

fn main() {
    let input = "&Foo <Ba>r &&";
    let input2 = "& < > << && >>>";

    println!("{} converted to: {}", input, replace_char(input));
    println!("{} converted to: {}", input2, replace_char(input2));
}