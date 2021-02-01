
#[cfg(example01)]
fn example() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}

#[cfg(example02)]
fn example() {
    const ALMA: u32 = 5;
    ALMA = 6;
}

#[cfg(example03)]
fn example() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    for val in v1_iter {
        println!("Got: {}", val);
    }
    for val in v1_iter {  // error: use of moved value: `v1_iter`
        println!("Got: {}", val);
    }
}

fn example() {
    
}

fn main() {
    example();
}
