#![allow(dead_code, unused)]

use std::io::*;
use std::{isize, usize};
use std::collections::*;
use std::mem::swap;
use std::cmp::{max, min};
type Queue<T> = LinkedList<T>;

struct Scanner<R: BufRead> {
  reader: R,
  buf_str: Vec<u8>,
  buf_iter: std::str::SplitAsciiWhitespace<'static>,
}
impl<R: BufRead> Scanner<R> {
  fn new(reader: R) -> Self {
    Self {
      reader,
      buf_str: vec![],
      buf_iter: "".split_ascii_whitespace(),
    }
  }
  fn scan<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buf_iter.next() {
        return token.parse().ok().expect("Failed to parse.");
      }
      self.buf_str.clear();
      self.reader
        .read_until(b'\n', &mut self.buf_str)
        .expect("Failed to read.");
      self.buf_iter = unsafe {
        let slice = std::str::from_utf8_unchecked(&self.buf_str);
        std::mem::transmute(slice.split_ascii_whitespace())
      };
    }
  }
}
fn _i() -> &'static mut Scanner<StdinLock<'static>> {
  static mut SCN: Option<Scanner<StdinLock>> = None;
  unsafe {
    if let None = SCN {
      SCN = Some(Scanner::new(stdin().lock()));
    }
    return SCN.as_mut().unwrap();
  }
}
fn _o() -> &'static mut BufWriter<StdoutLock<'static>> {
  static mut WRT: Option<BufWriter<StdoutLock>> = None;
  unsafe {
    if let None = WRT {
      WRT = Some(BufWriter::new(stdout().lock()));
    }
    return WRT.as_mut().unwrap();
  }
}
macro_rules! input {
  ()=>{}; ()=>[];
  (mut $v:ident:$t:tt,$($r:tt)*)=>{input!(mut $v:$t);input!($($r)*);};
  (mut $v:ident:$t:tt)=>{let mut $v=input_inner!($t);};
  ($v:ident:$t:tt,$($r:tt)*)=>{input!($v:$t);input!($($r)*);};
  ($v:ident:$t:tt)=>{let $v=input_inner!($t);};
  (($($v:tt)*):($($t:tt),*),$($r:tt)*)=>{input!(($($v)*):($($t),*));input!($($r)*);};
  (($($v:tt)*):($($t:tt),*))=>{let ($($v)*)=input_inner!(($($t),*));};
}
macro_rules! input_inner {
  (($($t:tt),*))=>{($(input_inner!($t)),*)};
  ([$t:tt;$n:expr])=>{(0..$n).map(|_| input_inner!($t)).collect::<Vec<_>>()};
  ([$t:tt;$pad:expr;$n:expr])=>{{
    let mut tmp=Vec::with_capacity(($pad)+($n));
    tmp.resize_with(($pad),Default::default);
    tmp.resize_with(($pad)+($n),|| input_inner!($t));tmp
  }};
  (chars)=>{input_inner!(String).chars().collect::<Vec<_>>()};
  (vytes)=>{input_inner!(String).bytes().collect::<Vec<_>>()};
  (bytes)=>{input_inner!(String).into_bytes()};
  (usize_1)=>{input_inner!(usize)-1};
  ($t:ty)=>{_i().scan::<$t>()};
}
macro_rules! test {($n:expr)=>(for _ in 0..tny!(($n)!=0;($n);_i().scan()){solve();})}
macro_rules! tny {($c:expr;$t:expr;$f:expr)=>{if $c{$t}else{$f}};}
macro_rules! println {($($fmt:tt)*)=>(writeln!(_o(),$($fmt)*))}
macro_rules! print {($($fmt:tt)*)=>(write!(_o(),$($fmt)*))}
macro_rules! flush {()=>{_o().flush().unwrap()};}

fn main() { test!(1); flush!(); }
fn solve() {
  input! {
    n: usize,
    a: [usize; n],
  }
  for i in 0..n {
    print!("{} ", a[i]);
  }
  println!();
}
